def s(r, n):
    return 2*r*n + 2*n*n - n

def find_max(r, t):
    min_n = 0
    max_n = t
    while max_n - min_n > 1:
        curr_n = (max_n - min_n) / 2 + min_n
        if s(r, curr_n) <= t:
            min_n = curr_n
        else:
            max_n = curr_n
    
    if s(r, max_n) <= t:
        curr_n = max_n
    else:
        curr_n = min_n

    return curr_n

def do_case(case_num, r, t):
    result = find_max(r, t)
    print "Case #%d: %d" % (case_num, result)

def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        r, t = map(int, raw_input().split())
        do_case(case_num, r, t)

if __name__ == "__main__":
    main()
