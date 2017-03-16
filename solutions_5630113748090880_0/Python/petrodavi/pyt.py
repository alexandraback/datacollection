import sys

name="./small.txt"

def algo1(tt, mdict, N):

    intermediate_buff = []

    # check all dublons in the dict. all values that are not double
    # are candidates to be the missing list
    # list has to be ordered at the end, do not miss it :D

    for index, values in mdict.iteritems():
        if values % 2 != 0:
            intermediate_buff.append(index)

    # check that len should NOT be more than N
    assert len(intermediate_buff) == N

    intermediate_buff.sort()

    return intermediate_buff

def main():

    global name

    if len(sys.argv) > 1:
        name = sys.argv[1]

    fl = open(name, 'r')
    fl_wrt = open(name + "_reply", 'w')

    tt = int(fl.readline())
    i = 0

    reply = ''

    while (i < tt):
        i = i+1

        mdict = {}

        numb_rows = int(fl.readline())

        for tmp in xrange(0, numb_rows * 2 - 1):
            numb = fl.readline().rstrip().split()
            numb = [int(a) for a in numb]
            for value in numb:
                if not mdict.has_key(value):
                    mdict[value] = 0
                increase_me = mdict.get(value)
                mdict[value] = increase_me + 1

        buff = algo1(tt, mdict, numb_rows)

        reply = reply + "Case #{0}: {1}\n".format(i, " ".join(str(x) for x in buff))

    fl_wrt.write(reply)

    fl.close()
    fl_wrt.close()


if __name__ == "__main__":
    main()
