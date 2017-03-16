def solve(n, naomi, ken):
    ni, ki = 0, 0
    ken_honest_wins = 0
    while ki < n:
        if naomi[ni] < ken[ki]:
            ken_honest_wins += 1
            ni += 1
        ki += 1

    ni, klow, khigh = 0, 0, n - 1
    ken_deceit_wins = 0
    while ni < n and klow <= khigh:
        if naomi[ni] > ken[klow]:
            klow += 1
        else:
            ken_deceit_wins += 1
            khigh -= 1
        ni += 1

    return n - ken_deceit_wins, n - ken_honest_wins

def main():
    T = int(input())
    for i in range(1, T + 1):
        N = int(input())
        naomi = [float(x) for x in input().strip().split()]
        naomi.sort()
        ken = [float(x) for x in input().strip().split()]
        ken.sort()
        deceit_points, war_points = solve(N, naomi, ken)
        #print(naomi, ken, sep='\n')
        print('Case #', i, ': ', deceit_points, ' ', war_points, sep='')

if __name__ == '__main__':
    main()
