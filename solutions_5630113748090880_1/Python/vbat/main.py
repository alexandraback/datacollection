from itertools import tee, izip
from collections import defaultdict

importResults = list()

while True:
    try:
        text = raw_input()
        if len(text.strip()) == 0:
            break
        else:
            importResults.append(text.strip())
    except EOFError:
        break

def processCase(data):
    missing_line = []
    flat_data = [item for sublist in data for item in sublist]
    # print flat_data
    d = defaultdict(int)
    for height in flat_data:
        d[height]+=1
    for (k, v) in d.iteritems():
        if v % 2 != 0:
            missing_line.append(k)
    return " ".join(map(str, sorted(missing_line)))

preprocessedImport = []

i = 1
while i < len(importResults):
    n = int(importResults[i])
    thisCase = map(lambda x: map(lambda y: int(y), x.split()), importResults[i+1:i+2*n])
    preprocessedImport.append(thisCase)
    i += 2*n

# print preprocessedImport

for i in range(len(preprocessedImport)):
    print "Case #{case_id}: {result}".format(case_id = i+1, result = processCase(preprocessedImport[i]))



