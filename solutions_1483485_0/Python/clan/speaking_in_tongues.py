#!/usr/bin/python 

import string
import sys

table = string.maketrans("ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvqz","ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupzq")

f = open("input")
n = int(f.readline())
for i in xrange(n):
    original = f.readline().strip('\n')
    print "Case #%d: %s" % (i+1,original.translate(table))
