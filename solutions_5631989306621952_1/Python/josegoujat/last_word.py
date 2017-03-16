# Read problem
no_of_cases = int(raw_input())
cases = []
for _ in range(no_of_cases):
    cases.append(raw_input())

# Iterate cases
for i, case in enumerate(cases):
    output = case[0]

    for letter in case[1:]:
        if letter >= output[0]:
            output = letter + output
        else:
            output = output + letter

    print "Case #{}: {}".format(i+1, output)