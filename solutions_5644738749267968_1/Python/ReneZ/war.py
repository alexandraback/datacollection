from util import *

def checkList(a, b):
    i = 0
    for x in b:
        if x > a[i]:
            i += 1

    return i


def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in xrange(num):
        N = int(r.next())
        naomi = map(float, r.next().split(" "))
        naomi.sort()
        ken = map(float, r.next().split(" "))
        ken.sort()

        deceit = checkList(ken, naomi)
        war = N - checkList(naomi, ken)

        ans.append("%s %s" % (deceit, war))
    write("output", ans)

if __name__ == '__main__':
    main()
