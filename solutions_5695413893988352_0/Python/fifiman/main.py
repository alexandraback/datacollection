import sys
in_file = open("test.txt")
#in_file = sys.stdin


def fits(a,b):
    for c1,c2 in zip(a,b):
        if c2 != '?' and c1 != c2:
            return 0

    return 1

def solve(a,b):


    n = len(a)

    MINI = 1000000
    ans1,ans2 = "", ""

    for i in range(10 ** n):
        for j in range(10 ** n):
            

            s1 = str(i)
            s2 = str(j)

            if len(s1) > n or len(s2) > n:
                continue

            while len(s1) < n:
                s1 = '0' + s1

            while len(s2) < n:
                s2 = '0' + s2

            if not fits(s1,a) or not fits(s2,b):
                continue

            if abs(int(s1) - int(s2)) < MINI:
                MINI = abs(int(s1) - int(s2))
                ans1,ans2 = s1,s2


    return "%s %s" %(ans1,ans2)


data = in_file.read().strip().split()[1:]

t = 1


sys.stdout = open("out.txt", 'w')

while data:

    print "Case #%i: %s" %(t, solve(data[0], data[1]))

    t += 1
    data = data[2:]



#out_file = open('out.txt', 'w')
