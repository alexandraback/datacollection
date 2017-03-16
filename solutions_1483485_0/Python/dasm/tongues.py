#!/usr/bin/env python

import string
import sys

mapping = {}

def record(a, b):
  for (x, y) in zip(a, b):
    if x in mapping and not mapping[x] == y:
      print "conflict: " + x + ": " + y + " vs " + mapping[x]
    mapping[x] = y

def findMapping():
  record(
      "ejp mysljylc kd kxveddknmc re jsicpdrysi",
      "our language is impossible to understand")
  record(
      "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
      "there are twenty six factorial possibilities")
  record(
      "de kr kd eoya kw aej tysr re ujdr lkgc jv",
      "so it is okay if you want to just give up")
  record("y qee", "a zoo")

  used = set(mapping.values())

  uk = None
  uv = None

  for letter in string.lowercase:
    if not letter in mapping:
      uk = letter
    if not letter in used:
      uv = letter

  mapping[uk] = uv

def main():
  findMapping()
  i = sys.stdin.readlines()
  for (x, line) in enumerate(i[1:int(i[0])+1]):
    print "Case #" + str(x + 1) + ": " + \
      ''.join([mapping[x] for x in line.strip()])



main()
