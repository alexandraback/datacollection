import sys

test_cases = sys.stdin.readlines()[1:]
for case_index, case_data in enumerate(test_cases):
    max_shyness, audience = case_data.strip().split()
    friends_required = 0
    standing_up = 0
    for shyness, people_count in enumerate(audience):
        people_count = int(people_count)
        if shyness <= standing_up:
            standing_up += people_count
        else:
            friends_required += shyness - standing_up
            standing_up = shyness + people_count
    sys.stdout.write('Case #{}: {}\n'.format(case_index+1, friends_required))
