#!/usr/bin/python

import sys
import fractions
from fractions import Fraction
import itertools
import pickle

import puzutils

class Elf_2014_1CA(puzutils.CodeJamProblem):
  def __init__(self, inputFilename):
    puzutils.CodeJamProblem.__init__(self, inputFilename)

    self.T = None

    self.half = Fraction("1/2")
    #self.elf = {Fraction("1/1"):0, Fraction("0/1"):None}
    #self.bred = set()

#    try:
#      with open('elf40.pkl', 'rb') as input:
#        self.elf = pickle.load(input)
#    except:
#      self.breed()
#      with open('elf40.pkl', 'wb') as output:
#        pickle.dump(self.elf, output, pickle.HIGHEST_PROTOCOL)

  def load(self):
    """
      input:

      T (number of test cases)

      P/Q

    """

    self.tests = []

    with open(self.inputFilename, "rt") as file:
      self.T = int(file.readline().strip())

      for i in xrange(self.T):
        test = Fraction(file.readline().strip())

        self.tests.append(test)

    return True

  def breedTwo(self, p1, p2):
    """
      Breed two parents.
    """

    self.bred.add((p1,p2))

    k = Fraction((p1 + p2) / 2)

    #print "bred %s and %s = %s" % (p1, p2, k)

    return k

  def breedGen(self, gen, poss):
    kids = set([])
    g = gen + 1

    #print "poss: %s" % (poss, )

    for (p1,p2) in itertools.combinations_with_replacement(poss, 2):
      if ((p1,p2) in self.bred) or ((p2,p1) in self.bred):
        continue

      k = self.breedTwo(p1, p2)

      kids.add(k)

      try:
        if (self.elf[k] > g):
          self.elf[k] = g
      except KeyError:
        self.elf[k] = g

    #print "    kids: %s" % (kids, )
    return kids

  def breed(self):
    poss = set([Fraction("1/1"), Fraction("0/1")])
    gen = 0

    while (gen <= 40):
      print "generation: %d" % (gen, )
      kids = self.breedGen(gen, poss)
      gen = gen + 1
      poss = poss.union(kids)

  def executeTest(self, test):
    """
      Run a test and return output.
    """

    print "Test: %s\n" % (test, )

    # If the denom is not a power of two, then your point is invalid
    d = test.denominator
    if (d & (d-1)) != 0:
      return "impossible"

    # If at least a half, could be one generation ago
    g = 1
    while (test < self.half):
      g = g + 1

      test = Fraction(test.numerator, test.denominator / 2)

    return g

with Elf_2014_1CA(sys.argv[1]) as problem:
  problem.load()

  problem.run()
