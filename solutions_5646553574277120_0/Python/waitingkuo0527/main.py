from itertools import combinations

def _solve(C, D, V, coins):
    """ solve the problem """

    #print(C, D, V, coins)

    count = 0
    all_values = set([v+1 for v in range(V)])
    all_combinations = set()
    for v in range(V):
        if v in coins: continue
        for d in range(D):
            for choose in combinations(coins, d+1):
                all_combinations.add(sum(choose))
    
    remains = all_values - all_combinations

    #if len(remains) == 0: return 0
    #if len(remains) == 1: return 1

    return remains

def _kinds(D, coins, remains):
    remain = min(remains)
    kinds = set([])
    smaller_coins = set([])
    for coin in coins:
        if coin <= remain: smaller_coins.add(coin)
    for d in range(D+1):
        for choose in combinations(smaller_coins, d):
            needed = remain - sum(choose)
            if needed < 0: continue
            if kinds not in coins:
                kinds.add(needed)
    return kinds

def solve(C, D, V, coins):

    remains = _solve(C, D, V, coins)
    if len(remains) == 0: return 0
    if len(remains) == 1: return 1

    queue = []
    kinds = _kinds(D, coins, remains)
    for new_coin in kinds:
        new_coins = coins.copy()
        new_coins.add(new_coin)
        queue.append([D+1, new_coins])
            
    while True:
        cur_data = queue.pop(0)
        cur_D = cur_data[0]
        cur_coins = cur_data[1]
        cur_remains = _solve(C, cur_D, V, cur_coins)
        if len(cur_remains) == 0: 
            #print(cur_coins)
            return cur_D - D
        kinds = _kinds(cur_D, cur_coins, cur_remains)
        for new_coin in kinds:
            new_coins = cur_coins.copy()
            new_coins.add(new_coin)
            queue.append([cur_D+1, new_coins])

    return remains

def parse():
    """ parse input """

    C, D, V = [int(i) for i in input().split()]
    coins = set([int(i) for i in input().split()])

    return C, D, V, coins


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
