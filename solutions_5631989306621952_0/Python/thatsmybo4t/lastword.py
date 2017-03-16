def last_word(s):
    last = ""
    for l in s:
        if len(last) == 0:
            last += l
        else:
            if l >= last[0]:
                last = l + last
            else:
                last += l
    return last

def main():
    t = input()
    for i in xrange(1,t+1):
        s = raw_input().strip()
        last = last_word(s)
        print "Case #%d: %s" % (i,last)

if __name__ == "__main__":
    main()
