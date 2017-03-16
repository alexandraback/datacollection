def solve(s):
    answer = ""
    for x in s:
        if len(answer) == 0 or ord(x) >= ord(answer[0]):
           answer = x + answer
        else:
           answer = answer + x
    return answer


for t in range(1, int(raw_input()) + 1):
    print "Case #%d: %s" % (t, solve(raw_input()))