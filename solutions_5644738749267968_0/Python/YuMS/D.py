from bisect import bisect_right
def solve():
    N = input()
    Naomi = raw_input()
    Ken = raw_input()
    Naomi_w = map(float, Naomi.split())
    Ken_w = map(float, Ken.split())
    Naomi_w.sort()
    Ken_w.sort()
    Naomi = Naomi_w[:]
    Ken = Ken_w[:]
    score = 0
    for i in range(len(Naomi)):
        if Naomi[0] < Ken[0]:
            Ken = Ken[:-1]
        else:
            score += 1
            Ken = Ken[1:]
        Naomi = Naomi[1:]
        #print Naomi
        #print Ken
    print score,
    Naomi = Naomi_w[:]
    Ken = Ken_w[:]
    score = 0
    for i in range(len(Naomi)):
        next = bisect_right(Ken, Naomi[0])
        if next == len(Ken):
            score += 1
            Ken = Ken[1:]
        else:
            Ken.remove(Ken[next])
        Naomi = Naomi[1:]
        #print Naomi
        #print Ken
    print score

def main():
    T = input()
    for i in range(1, T + 1):
        print 'Case #%d:' % i,
        solve()

if __name__ == '__main__':
    main()
