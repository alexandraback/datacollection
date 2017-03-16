from copy import copy

def dp(pos, firsts_count, lasts_count, firsts, lasts):
    if (pos >= len(firsts)): return 0

    # Try faking, if possible
    fake = 0
    if (firsts_count[firsts[pos]] >= 2 and lasts_count[lasts[pos]] >= 2):
        new_firsts = copy(firsts_count)
        new_lasts = copy(lasts_count)

        new_firsts[firsts[pos]] -= 2
        new_lasts[lasts[pos]] -= 2

        fake = 1 + dp(pos+1, new_firsts, new_lasts, copy(firsts), copy(lasts))

    # No fake
    no_fake = dp(pos+1, copy(firsts_count), copy(lasts_count), copy(firsts), copy(lasts))

    return max(fake, no_fake)

T = int(input(""))
for i in range(1,T+1):
    N = int(input(""))

    firsts_count = {}
    firsts = []
    lasts_count = {}
    lasts = []
    for j in range(N):
        name = input("")
        first_name = name.split()[0]
        last_name = name.split()[1]

        firsts.append(first_name)
        lasts.append(last_name)

        if (first_name in firsts_count.keys()): firsts_count[first_name] += 1
        else: firsts_count[first_name] = 1

        if (last_name in lasts_count.keys()): lasts_count[last_name] += 1
        else: lasts_count[last_name] = 1

    answer = dp(0, firsts_count, lasts_count, firsts, lasts)
    print("Case #%d: %d" % (i, answer))