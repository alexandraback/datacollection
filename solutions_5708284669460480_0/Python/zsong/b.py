def solve(keys, target, s):
    k = len(keys)
    l = len(target)

    max_prefix_length = 0
    for x in range(l):
        if target[0:x] == target[l - x:]:
            max_prefix_length = max(max_prefix_length, x)

    n_bananas = (s - max_prefix_length) // (l - max_prefix_length)

    key_hash = {}
    for x in keys:
        if x in key_hash:
            key_hash[x] += 1
        else:
            key_hash[x] = 1

    for x in target:
        if x not in key_hash:
            return 0.0

    p = 1

    for x in target:
        p *= key_hash[x] / k

    return (1 - p) * n_bananas


if __name__ == "__main__":
    testcases = int(input())

    for caseNr in range(1, testcases + 1):
        k, l, s = [int(x) for x in input().split()]
        keys = input()
        target = input()
        print("Case #%i: %.7f" % (caseNr, solve(keys, target, s)))