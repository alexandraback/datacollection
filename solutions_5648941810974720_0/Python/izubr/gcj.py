from collections import Counter

words = [
    "ZERO",
    "TWO",
    "FOUR",
    "FIVE",
    "SIX",
    "EIGHT",
    "ONE",
    "THREE",
    "SEVEN",
    "NINE"
]

only_lets = [
    "Z",
    "W",
    "U",
    "F",
    "X",
    "G",
    "O",
    "R",
    "V",
    "I"
]

nums = [
    0,
    2,
    4,
    5,
    6,
    8,
    1,
    3,
    7,
    9
]
t = int(raw_input(""))
for case in range(t): 
    s = raw_input("")
    letters = Counter(list(s))
    numbers = [0]*10
    for i, let in enumerate(only_lets):
        cur_n_of_number = letters[let]
        cur_number = nums[i]
        numbers[cur_number] = cur_n_of_number
        for w in words[i]:
            letters[w] -= cur_n_of_number
    result = ""
    for i, n in enumerate(numbers):
        result = result + n * str(i)
    print "Case #%s: %s" % (case + 1, result)

