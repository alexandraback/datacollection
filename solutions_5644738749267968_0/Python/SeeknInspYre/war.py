__author__ = 'Shailesh'

def search(ken, val):
    start = 0
    end = len(ken) - 1
    while start < end:
        mid = (start + end) / 2
        if ken[mid] < val < ken[mid + 1]:
            return mid + 1
        if ken[mid] < val:
            start = mid + 1
        else:
            end = mid
    if start == end and ken[start] > val:
        return start
    return -1

with open("../files/D-small-attempt0.in", 'r') as input, open("../files/output.txt", 'w') as output:
    t = int(input.readline())
    for i in xrange(t):
        answer = "Case #" + str(i+1) + ": "
        n = int(input.readline())
        naomi = sorted(map(float, input.readline().split()))
        ken = sorted(map(float, input.readline().split()))
        deceit = 0
        normal = 0
        naomi_copy = naomi[:]
        ken_copy = ken[:]
        l = []
        for i in xrange(n):
            if naomi[0] < ken[0]:
                naomi.pop(0)
                ken.pop(len(ken) - 1)
            else:
                deceit += 1
                naomi.pop(0)
                ken.pop(0)
        naomi = naomi_copy
        ken = ken_copy
        for i in xrange(n):
            val = naomi.pop(0)
            index = search(ken, val)
            if index == -1:
                ken.pop(0)
                normal += 1
            else:
                ken.pop(index)

        output.write(answer + str(deceit) + " " + str(normal) + "\n")