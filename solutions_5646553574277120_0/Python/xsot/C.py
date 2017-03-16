def f(i, rem, coins):
    if rem == 0:
        return True
    if i == len(coins) or rem < 0:
        return False
    return f(i+1, rem-coins[i], coins) or f(i+1, rem, coins) 
    

for tc in range(1, int(raw_input())+1):
    c, d, v = map(int, raw_input().split())
    coins = map(int, raw_input().split())
    
    val = 1
    additions = []
    while val < v:
        if not f(0, val, coins+additions):
            additions.append(val)
        val += 1
    print "Case #%d: %d" % (tc, len(additions))