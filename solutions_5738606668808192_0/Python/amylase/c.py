import random


def generate_candidate(n):
    fixed = [0, n-1]
    odd_source, even_source = range(1, n-1, 2), range(2, n-1, 2)
    odd, even = random.sample(odd_source, 2), random.sample(even_source, 2)
    return fixed + odd + even


def test(poses):
    candidates = [5, 7, 11]
    for candidate in candidates:
        if sum(pow(6, pos, candidate) for pos in poses) % candidate == 0:
            return candidate
    return None


def main():
    t = input()
    n, j = map(int, raw_input().strip().split())
    jamcoins = set()
    print "Case #1:"
    while len(jamcoins) < j:
        poses = generate_candidate(n)
        jamcoin = str(sum(10 ** i for i in poses))
        if jamcoin in jamcoins:
            continue
        res = test(poses)
        if res is not None:
            jamcoins.add(jamcoin)
            print jamcoin,
            facts = [3, 2, 3, 2, res, 2, 3, 2, 3]
            for fact in facts:
                print fact,
            print
            for i, fact in enumerate(facts):
                base = i + 2
                if len(jamcoin) != n or int(jamcoin, base) % fact != 0:
                    print "Violates condition!!"
                    exit()


if __name__ == '__main__':
    main()
