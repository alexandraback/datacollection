import sys

name = "./small.txt"

def algo1(tt, word):

    buff = word[0]

    for pos in xrange(1, len(word)):
        if word[pos] >= buff[0]:
            buff = word[pos] + buff
        else:
            buff = buff + word[pos]

    return str(buff)

def main():
    global name

    if len(sys.argv) > 1:
        name = sys.argv[1]

    fl = open(name, 'r')
    fl_wrt = open(name + "_reply", 'w')

    tt = int(fl.readline())
    i = 0

    reply = ''

    while i < tt:
        i = i+1

        word = fl.readline().rstrip()

        buff = algo1(tt, word)
        reply = reply + "Case #{0}: {1}\n".format(i, buff)

    fl_wrt.write(reply)

    fl.close()
    fl_wrt.close()


if __name__ == "__main__":
    main()
