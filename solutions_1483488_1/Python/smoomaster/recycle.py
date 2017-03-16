

def recycle(f):
    num_entries = int(f.readline())
    for entry_no in range(num_entries):
        entries = [int(x) for x in f.readline().strip().split(' ')]
        low = entries[0]
        high = entries[1]
        target = entries.pop(0)
        count = 0
        digits = len(str(high))
        top_exp = pow(10, digits-1)
        rotations = []
        
        for i in range(low, high+1):
            rotated = i
            for z in range(digits-1):
                rotated = (rotated // top_exp) + 10*(rotated % top_exp)
                if rotated > i and rotated >= low and rotated <= high and rotated not in rotations:
                    rotations.append(rotated)
                    count += 1
            rotations[:] = []

        print('Case #%d: %d' % (entry_no+1, count))

    f.close()

import sys
recycle(open(sys.argv[1]))
