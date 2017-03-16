def flip(c):
    if c == '+':
        return '-'
    else:
        return '+'


def flip_range(pile, p):
    left, right = 0, p - 1
    while left <= right:
        pile[left], pile[right] = flip(pile[right]), flip(pile[left])
        left, right = left + 1, right - 1


def solve():
    pile = list(raw_input())
    pt = len(pile)
    answer = 0
    while pt > 0:
        while pt > 0 and pile[pt - 1] == '+':
            pt -= 1
        if pt > 0:
            if pile[0] == '+':
                answer += 1
                flip_range(pile, pile.index('-'))
            answer += 1
            flip_range(pile, pt)
    return answer


T = int(raw_input())
for case_no in xrange(1, T + 1):
    print "Case #%d: %s" % (case_no, str(solve()))
