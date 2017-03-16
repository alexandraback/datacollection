def generate_collection(i, C, K):
    """
    Returns a number that will effectively guess all of the tiles
    from i to i + C.

    Crappy explanation, but gcj demands quick and dirty solutions
    """
    if i >= K:
        return 0
    if C == 1:
        return i
    total = K ** C
    start_of_block = i * (total / K)
    place_in_block = generate_collection(i + 1, C - 1, K)
    return start_of_block + place_in_block

def solve(K, C, S):
    if S * C < K:
        return "IMPOSSIBLE"
    results = []
    for i in xrange(0, K, C):
        results.append(generate_collection(i, C, K) + 1)
    return ' '.join(str(i) for i in results)

T = int(raw_input())
for i in xrange(1, T+1):
    K, C, S = map(int, raw_input().split())
    solution = solve(K, C, S)
    print "Case #%i:" % i, solution
