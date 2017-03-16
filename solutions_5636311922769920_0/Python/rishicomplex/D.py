def work(index):
    print "Case #" + str(index) + ":",
    K, C, S = map(int, raw_input().split(' '))
    m = (K + C - 1) / C
    if S < m:
        print "IMPOSSIBLE"
        return
    level = 0
    report = 1
    section = 1
    for ind in xrange(K, 0, -1):
        report += ((ind - 1) * section)
        level += 1
        section *= K
        if(level == C or ind == 1):
            print report,
            report = 1
            section = 1
            level = 0
    print        
    

def main():
    T = int(raw_input())
    for i in xrange(1, T + 1):
        work(i)

main()
