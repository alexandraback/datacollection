def solve(trains, letters, trains_dict, last_letter):
    if not trains:
        return 1
    total = 0
    original_last_letter = last_letter
    for train in list(trains):
        new_set = set()
        word = trains_dict[train]
        for letter in word:
            if letter == last_letter:
                continue
            if (letter in new_set) or (letter in letters):
                return 0
            last_letter = letter
            new_set.add(letter)

        trains.remove(train)
        total += solve(trains, letters|new_set, trains_dict, last_letter)
        trains.add(train)
        last_letter = original_last_letter

    return total

t = int(input())

for i in range(1, t+1):
    num_trains = int(input())
    trains = input().split()
    trains_dict = dict(zip(range(num_trains), trains))
    answer = solve(set(range(num_trains)), set(), trains_dict, None)
    answer %= 1000000007
    print('Case #%s: %s'%(i, answer))