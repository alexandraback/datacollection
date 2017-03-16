
T = int(raw_input())
for case_no in xrange(1, T + 1):
    s = raw_input()
    answer = ""
    for c in s:
        answer = max(c + answer, answer + c)
    print "Case #%d: %s" % (case_no, answer)