inputF = open('C-small-1-attempt1.in', 'r')
output = open('C-small-1-attempt1.out', 'w')

numCases = int(inputF.readline())

# In the simple case with two hikers, the worst we can possibly do is
# one encounter. So figure out whether that is necessary or not.

# Question is whether our region is collapsed before or after we can reach start

# Get time til slow hiker finishes
# If fast hiker starts in front of us:
#   - time for loop + finish
# else:
#   - time til catches slow hiker
# If slow finish is greater, than we are caught



# hikers are (pos, lapTime)
def getEncounters(hikers):
    if len(hikers) <= 1:
        return 0
    elif len(hikers) > 2:
        print "Bad input"
        return 0
    if hikers[0][1] < hikers[1][1]:
        fast = hikers[0]
        slow = hikers[1]
    else:
        fast = hikers[1]
        slow = hikers[0]

    slowFinishTime = slow[1]*1.0*(360-slow[0])/360

    if fast[0] <= slow[0]:
        fastFinishTime = fast[1] + fast[1]*1.0*(360-fast[0])/360
    else:
        x = slow[0]+360
        y = fast[0]
        n = 360.0/slow[1]
        m = 360.0/fast[1]
        if m == n:
            return 0
        z = (m*x - n*y) / (m-n)
        fastFinishTime = (z-x)/n

    if slowFinishTime >= fastFinishTime:
        return 1
    else:
        return 0



for i in range(numCases):
    numGroups = int(inputF.readline())
    hikers = []
    for j in range(numGroups):
        group = map(lambda x: int(x), inputF.readline().split())
        numHikers = group[1]
        pos = group[0]
        for k in range(numHikers):
            hikers += [(pos, group[2]+k)]

    enc = getEncounters(hikers)
    

    output.write('Case #' + str(i+1) + ': ')
    output.write(str(enc) + '\n')




inputF.close()
output.close()
