import itertools
import functools
import statistics


def occurrences(sub, string):

    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:

            count += 1

        else:

            return count

for case in range(int(input())):

    k, l, s = map(int, str.split(input()))
    keyboard = input()
    word = input()
    occur = functools.partial(occurrences, word)
    if not set(keyboard) >= set(word):

        data = (0,)

    else:

        data = tuple(map(occur, map("".join, itertools.product(keyboard, repeat=s))))


    r = max(data) - statistics.mean(data)
    print(str.format("Case #{}: {}", case + 1, r))
