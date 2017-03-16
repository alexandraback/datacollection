import sys

def solveCase(f):
    l = map(int, f.readline().split())
    contestants = l[0]
    points = l[1:]
    minPercents = [g(points, index) for index in xrange(len(points))]


    return " ".join(map(str, minPercents))

# total score = (jury score) + (total jury scores)*(fraction of audience votes)
def g(points, index):
    totalPoints = sum(points)
    myPoints = points[index]
    otherPoints = points[0:index] + points[index + 1:]
    competitor = min(otherPoints)
    len_points = len(points)
    if myPoints == totalPoints:
        return float(0)
    elif totalPoints in otherPoints:
        len_points -= 1
    #x = (2 * (competitor - myPoints)) / float(totalPoints) + 2
    #x = (competitor + totalPoints - myPoints) / float(2 * totalPoints)
    x = 2 / float(len_points) - min(myPoints, 1) / float(totalPoints)
    return x * 100
    
def main(fName):
    f = open(fName, "r")
    cases = int(f.readline())
    for i in xrange(cases):
        print "Case #%d: %s" % (i + 1, solveCase(f))
    f.close()

main(sys.argv[1])
