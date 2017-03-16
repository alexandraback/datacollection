#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys, os
import argparse
import time
import re
import math
import random
import numpy as np
import pickle
import subprocess as sp
import multiprocessing as mp


class Reader(object):
  endOfWord = re.compile('\s|$')
  
  def __init__(self, handle):
    self.handle = handle
    self.buf = ''
  
  def ok(self):
    return bool(self.handle)
  
  def getLine(self):
    if self.buf: return self.buf
    if self.handle: return self.handle.readline()[:-1]
    return ''
  
  def get(self, t=str):
    return t(self.getWord())
  
  def getWord(self):
    while self.handle and (not self.buf): self.buf = self.handle.readline().strip()
    if (not self.handle) and (not self.buf): return ''
    p = re.search(self.endOfWord, self.buf).start()
    word = self.buf[:p]
    self.buf = self.buf[p:].lstrip()
    return word


class Test(object):
  def __init__(self, case):
    self.case = case
  
  def read(self, reader):
    self.C, self.D, self.V = [reader.get(int) for _ in range(3)]
    self.d = [reader.get(int) for _ in range(self.D)]
  
  def solve(self, handle):
    handle.write('Case #%d: ' % self.case)
    
    C, D, V, d = self.C, self.D, self.V, self.d
    
    b = [False for _ in range(V+1)]
    
    b[0] = True
    
    for dd in d:
      bb = b[:]
      for i in range(dd, V+1):
        if bb[i - dd]:
          b[i] = True
    
    result = 0
    for i in range(V+1):
      if not b[i]:
        aa = i
        result += 1
        bb = b[:]
        for i in range(aa, V+1):
          if bb[i - aa]:
            b[i] = True
    
    handle.write('%d\n' % result)


def slave(args):
  testFn = args.test_case
  testName = testFn[:-7]
  testTmpFn = testName+'.tmp'
  test = pickle.load(open(testFn, 'rb'))
  testTmpHandle = open(testTmpFn, 'wt')
  test.solve(testTmpHandle)
  testTmpHandle.close()
  testOutFn = testName+'.out'
  os.rename(testTmpFn, testOutFn)


def split(args):
  inputFn = args.input_file
  ret = []
  inputName = inputFn[:-3] if inputFn.endswith('.in') else inputFn
  testsDir = inputName + '_split'
  if not os.path.isdir(testsDir): os.mkdir(testsDir)
  handle = open(inputFn, 'rt')
  reader = Reader(handle)
  tests = reader.get(int)
  for i in range(1, tests+1):
    testFn = os.path.join(testsDir, '%.5d.pickle' % i)
    if (not os.path.exists(testFn)) or args.clean_pickles:
      test = Test(i)
      test.read(reader)
      testHandle = open(testFn, 'wb')
      pickle.dump(test, testHandle)
      testHandle.close()
    ret.append(testFn)
  handle.close()
  return ret


def runSolveMode(semaphore, prog, inputFn, testFn):
  testName = testFn[:-7]
  semaphore.acquire()
  testOutFn = testName+'.out'
  if not os.path.exists(testOutFn):
    print('Solving ``%s\'\'...' % testName)
    sp.call([prog, inputFn, '--test-case', testFn])
  else:
    print('``%s\'\' already solved...' % testName)
  semaphore.release()


def merge(inputFn, testFns):
  inputName = inputFn[:-3] if inputFn.endswith('.in') else inputFn
  outputFn = inputName+'.out'
  handle = open(outputFn, 'wt')
  for testFn in testFns:
    testName = testFn[:-7]
    testOutFn = testName+'.out'
    assert os.path.exists(testOutFn)
    for line in open(testOutFn, 'rt'): handle.write(line)
  handle.close()


def master(args, prog):
  inputFn = args.input_file
  testFns = split(args)
  semaphore = mp.BoundedSemaphore(args.jobs)
  if args.clean_results:
    for testFn in testFns:
      testName = testFn[:-7]
      testOutFn = testName+'.out'
      if os.path.exists(testOutFn): os.unlink(testOutFn)
  processes = [mp.Process(target=runSolveMode, args=(semaphore, prog, inputFn, testFn)) for testFn in testFns]
  if not args.keep_order: random.shuffle(processes)
  for proc in processes: proc.start()
  for proc in processes: proc.join()
  merge(inputFn, testFns)


def main():
  parser = argparse.ArgumentParser(description='Solve some GCJ task.')
  parser.add_argument('input_file', metavar='INPUT_FILE')
  parser.add_argument('--test-case')
  parser.add_argument('-p', '--clean-pickles', action='store_true')
  parser.add_argument('-r', '--clean-results', action='store_true')
  parser.add_argument('-j', '--jobs', type=int, default=5)
  parser.add_argument('-o', '--keep-order', action='store_true')
  args = parser.parse_args()
  
  if args.test_case == None: master(args, sys.argv[0])
  else: slave(args)

if __name__ == '__main__': main()
