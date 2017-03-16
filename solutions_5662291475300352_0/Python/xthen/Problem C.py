def sameStart(d, m1, m2):
    if (m2/m1) < (1 + 360/(360-d)):
        return 0
    else:
        return 1


def diffStart(d1, d2, m1, m2):
    if (m2 * (360-d2)/360) < (m1 + (m1 * (360-d1)/360)):
        return 0
    else:
        return 1

with open('C-small-1-attempt0.in') as f:
    stuff = f.readlines()

case = 1
x = 1

while x < len(stuff):

    if stuff[x] == '1\n':

        string = list(map(int, stuff[x+1].split()))
        if string[1] == 1:
            print("Case #"+str(case)+": 0")
        else:
            print("Case #"+str(case)+": "+str(sameStart(string[0], string[2], string[2]+1)))

        case += 1
        x += 2

    else:

        string1 = list(map(int, stuff[x+1].split()))
        string2 = list(map(int, stuff[x+2].split()))
        if string1[2] < string2[2]:
            print("Case #"+str(case)+": "+str(diffStart(string1[0], string2[0], string1[2], string2[2])))
        elif string2[2] < string1[2]:
            print("Case #"+str(case)+": "+str(diffStart(string2[0], string1[0], string2[2], string1[2])))
        else:
            print("Case #"+str(case)+": 0")

        case += 1
        x += 3