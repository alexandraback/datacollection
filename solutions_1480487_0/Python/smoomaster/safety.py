import math

def safety(f):
    num_entries = int(f.readline())
    for entry_no in range(num_entries):
        entries = [int(x) for x in f.readline().strip().split(' ')]
        count = entries.pop(0)
        total = sum(entries)
        target = math.ceil(2*(total/count))

        out = []
        for entry in entries:
            out.append(str(100*max(0, target-entry)/total))

        print('Case #%d: %s' % (entry_no+1, ' '.join(out)))

    f.close()

import sys
safety(open(sys.argv[1]))
