import string
import math

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))

def do_calc(i):
    d = int(string.strip(testcase.readline()))
    plates = map(int, string.split(string.strip(testcase.readline())))
    plates.sort()
    plates.reverse()
    best_mins = plates[0]
    tries = [best_mins]
    # 1 special minute
    results = []
    results.append(plates[0]/2 + plates[0]%2 + 1)
    if d >= 2:
        results.append(plates[1] + 1)
    tries.append(max(results))
    # 2 special minutes
    results = []
    results.append(plates[0]/3 + (1 if plates[0]%3 else 0) + 2)
    if d >= 2:
        results.append(plates[1] + 2)
    tries.append(max(results))
    if d >= 2:
        results = []
        results.append(plates[0]/2 + plates[0]%2 + 2)
        if d >= 3:
            results.append(plates[2] + 2)
        tries.append(max(results))
    # 3 special minutes
    results = []
    results.append(plates[0]/4 + (1 if plates[0]%4 else 0) + 3)
    if d >= 2:
        results.append(plates[1] + 3)
    tries.append(max(results))
    if d >= 2:
        results = []
        results.append(plates[0]/3 + (1 if plates[0]%3 else 0) + 3)
        results.append(plates[1]/2 + plates[1]%2 + 3)
        if d >= 3:
            results.append(plates[2] + 3)
        tries.append(max(results))
    if d >= 3:
        results = []
        results.append(plates[0]/2 + plates[0]%2 + 3)
        if d >= 4:
            results.append(plates[3] + 3)
        tries.append(max(results))
    best_mins = min(tries)
    print "Case #"+str(i)+": "+str(best_mins)

for i in xrange(1, num_cases+1):
    do_calc(i)
