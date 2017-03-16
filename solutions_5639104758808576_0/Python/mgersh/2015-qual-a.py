import string
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))


def do_calc(i):
    vals = string.split(string.strip(testcase.readline()))
    smax = int(vals[0])
    shy_counts = []
    extra_people = 0
    people = 0
    for shyness in xrange(smax+1):
        num_this_level = int(vals[1][shyness])
        if num_this_level > 0:
            if shyness <= people:
                people += num_this_level
            else:
                extra_people += shyness - people
                people += extra_people + num_this_level
    print "Case #"+str(i)+": "+str(extra_people)

for i in xrange(1, num_cases+1):
    do_calc(i)
