import sys

file = sys.stdin
def getInt():
    return (file.readline())
def getInts():
    vals = list()
    for s in file.readline().split():
        vals.append(s)
    return vals

getInt()
vals = getInts()
n = int(vals[0])
j = int(vals[1])

result = list()
counter = 0

while counter < 2**(n-2):
    while len(result) < j:
        for i in range(2,11):
            valid = True
            if int( "1" + (format(counter, "b").zfill(n-2)) + "1", i) % (i+1) != 0:
                valid = False
                #print("not this one")
                break
        if valid:
            result.append("1" + (format(counter, "b").zfill(n-2))  + "1")
            #print("found one: " + "1" + (format(counter, "b").zfill(n-2)) + "1")
        #print("1" + (format(counter, "b").zfill(n-2)) + "1")
        counter += 1
    break

#print(len(result))
print("Case #1:")
for res in result:
    print(res + " 3 4 5 6 7 8 9 10 11")