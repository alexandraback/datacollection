import sys

def main(number):
    if number == 0:
        return "INSOMNIA"
    answer = set()
    current = number
    while True:
        answer = answer.union(set(str(current)))
        if len(answer) == 10:
            return str(current)
        current = current + number

T = int(raw_input())
for x in xrange(T):
    print "Case #" + str(x + 1) + ": " + main(int(raw_input()))
