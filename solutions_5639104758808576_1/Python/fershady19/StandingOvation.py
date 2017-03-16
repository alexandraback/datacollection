f = open("/Users/fernandorenteria/Documents/CodeJam/A-large.in", "r")
inputData = []
for line in f:
    inputData.append(line)


def StandingOvation(a):
    people = 0
    add = 0       
    for x in range(len(a)):    
        people += int(a[x])
        if people < x+1:
            add+=1
            people += 1
    return add

thisline = []    
for i in inputData:
    thisline.append(i.split(" "))


for i in range(int(inputData[0])):
    arr = []
    for j in range(len(thisline[i+1][1])-1):
        arr.append(thisline[i+1][1][j])
    print "Case #%s: %d" %(i+1,StandingOvation(arr))
