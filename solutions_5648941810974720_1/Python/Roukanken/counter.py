from collections import Counter

def work():
    x = input().strip()
    res = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    count = Counter(x)
    
    data = [
        ("Z", "ZERO", 0),
        ("W", "TWO", 2),
        ("U", "FOUR", 4),
        ("X", "SIX", 6),
        ("G", "EIGHT", 8),
        ("T", "THREE", 3),
        ("S", "SEVEN", 7),
        ("F", "FIVE", 5),
        ("O", "ONE", 1),
        ("I", "NINE", 9)
    ]

    for ident, name, num in data:
        res[num] = count[ident]

        for char in name:
            count[char] -= res[num]

    s = ""
    for num, times in enumerate(res):
        s += str(num) * times

    return s

T = int(input())
for test_case in range(T):
    print ("Case #{}:".format(test_case+1), work())