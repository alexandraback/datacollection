# f = open('input.txt')
# f = open('/home/aaronm/Desktop/A-small-attempt0.in')
f = open('/home/aaronm/Desktop/A-large.in')
t = int(f.readline())

for case in range(t):
    s = f.readline().strip()
    # print s
    news = ""
    for c in s:
        try:
            first = news[0]
        except:
            first = ''
        if c >= first:
            news = c + news
        else:
            news = news + c

    print "Case #%s: %s" % (case+1, news)