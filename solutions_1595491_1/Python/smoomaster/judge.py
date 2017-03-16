
def judge(f):
    num_entries = int(f.readline())
    for entry_no in range(num_entries):
        entries = [int(x) for x in f.readline().strip().split(' ')]
        count = entries.pop(0)
        surprises = entries.pop(0)
        target = entries.pop(0)
        threshold = target + 2*max(target-1, 0)
        surprise_threshold = target + 2*max(target-2, 0)
        wins = len([x for x in entries if x >= threshold])
        suprise_wins = min(surprises, len([x for x in entries if x < threshold and x >= surprise_threshold]))
        print('Case #%d: %d' % (entry_no+1, wins+suprise_wins))

    f.close()

import sys
judge(open(sys.argv[1]))
