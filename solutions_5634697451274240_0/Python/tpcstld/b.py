import itertools

def main(data):
    answer = 0
    data = [k for k, g in itertools.groupby(data)]
    for c in data[1:]:
        if c == '-':
            answer = answer + 2

    if data[0] == '-':
        answer = answer + 1
    return str(answer)

T = int(raw_input())
for x in xrange(T):
    print "Case #" + str(x + 1) + ": " + main(raw_input())
