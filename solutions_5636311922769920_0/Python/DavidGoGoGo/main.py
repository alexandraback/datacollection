def calc(k, first, second):
    return (first-1)*k + second

def getLocation(k, seq, start, end):
    tempLocation = seq[start]
    while start < end:
        tempLocation = calc(k, tempLocation, seq[start+1])
        start += 1
    return tempLocation

def getTile(K, C, S):
    seq = list(range(0, K + 1))
    t = 0
    if K % C != 0:
        t = C - K % C
    seq += [seq[K]] * t
    #print(seq)
    start = 1
    end = C
    res = []
    while end < len(seq):
        res.append(getLocation(K, seq, start, end))
        start += C
        end += C
    return res


def main():
    f = open('input.txt', 'r')
    t = int(f.readline())
    ofile = open("output.txt" , 'w')
    for i in range(1, t+1):
        k, c, s = [int(s) for s in f.readline().split(' ')]
        res = getTile(k, c, s)
        ofile.write("Case #{}:".format(i))
        for j in res:
            ofile.write(" {}".format(j))
        ofile.write("\n")

main()