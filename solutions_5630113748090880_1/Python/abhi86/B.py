#/usr/bin/env python

def get_missing_row(soldiers):
    num_count = {}
    for row in soldiers:
        for soldier in row:
            if soldier not in num_count:
                num_count[soldier] = 1
            else:
                num_count[soldier] += 1

    missing_row = []
    for n in num_count:
        if num_count[n] % 2 != 0:
            missing_row.append(n)

    return ' '.join(map(str, sorted(missing_row)))

if __name__ == '__main__':
    T = int(raw_input())
    for tc in range(1, T + 1):
        N = int(raw_input())
        soldiers = []
        for i in range(2 * N - 1):
            soldier_row = map(int, raw_input().split())
            soldiers.append(soldier_row)
        print 'Case #%d: %s' % (tc, get_missing_row(soldiers))
