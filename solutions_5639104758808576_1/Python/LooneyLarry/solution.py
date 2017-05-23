# Google Code Jam 2015 Qualifying A.
import sys

def doCase(file):
    invite = 0                  # Number of friends to invite
    standing = 0                # Number of people currently standing
    audience = file.readline().split()[1]
    shyness = 0                 # Shyness of next group
    while len(audience) > 0:
        numPeople = int(audience[0]) # Number of people in next group
        # If not enough people standing
        if standing < shyness:
            # Invite this many more friends.
            invite += shyness - standing
            standing = shyness  # Satisfied requirement
        standing += numPeople
        shyness += 1
        audience = audience[1:]
    return invite

def run():
    file = open(sys.argv[1])
    numCases = int(file.readline())
    for case in range(1, numCases+1):
        answer = doCase(file)
        print 'Case #{0}: {1}'.format(case, answer)
run()
