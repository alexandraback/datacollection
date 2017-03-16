import itertools

def check(seq, bff):
    N = len(seq)
    for x in range(len(seq)):
        pre_pos = seq[(x - 1 + N) % N]
        pos = seq[x]
        next_pos = seq[(x + 1) % N]
        if (bff[pos] != next_pos and bff[pos] != pre_pos):
            return False
    return True

def solve_():
    N = int(input())
    bff = map(int, input().split())
    bff = list(map(lambda x : x - 1, bff))

    for i in range(N, 2, -1):
        for seq in list(itertools.combinations(range(N), i)):
            for perm_seq in list(itertools.permutations(seq)):
                if (check(perm_seq, bff)):
                    return i
    return 2

def solve():
    T = int(input())
    for case_id in range(1, T + 1):
        ans = solve_()
        print ("Case #%d: %d" %(case_id, ans))
        
if __name__ == "__main__":
    solve()
