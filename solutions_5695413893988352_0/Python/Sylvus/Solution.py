# Language       : Python 3
# Compiled Using : py_compile
# Version        : Python 3.4.3


def replace_string(chars, pos, new_c):
    result = ""
    for j in range(len(chars)):
        if pos == j:
            result += new_c
        else:
            result += chars[j]
    return result


with open("B-small-attempt0.in") as f:
    data = f.readlines()


test_case_counter = 0
test_cases = int(data[0][:-1])
line_counter = 1
for i in range(test_cases):
    test_case_counter += 1
    numbers = data[line_counter][:-1].split(" ")
    line_counter += 1
    first_number = numbers[0]
    second_number = numbers[1]
    assert(len(first_number) == len(second_number))
    are_the_same = True
    bigger = -1
    for i in range(len(first_number)):
        if first_number[i] == "?" and second_number[i] == "?":
            if are_the_same:
                # We can keep it that way.
                first_number = replace_string(first_number, i, "0")
                second_number = replace_string(second_number, i, "0")
            else:
                # Which one is bigger?
                assert(bigger == 0 or bigger == 1)
                if bigger == 0:
                    # First one is bigger, make it as small as possible:
                    first_number = replace_string(first_number, i, "0")
                    second_number = replace_string(second_number, i, "9")
                else:
                    first_number = replace_string(first_number, i, "9")
                    second_number = replace_string(second_number, i, "0")
        elif first_number[i] == "?" and second_number[i] != "?":
            if are_the_same:
                # Keep it that way:
                first_number = replace_string(first_number, i, second_number[i])
            else:
                assert(bigger == 0 or bigger == 1)
                if bigger == 0:
                    # First one is bigger, make it as small as possible:
                    first_number = replace_string(first_number, i, "0")
                else:
                    first_number = replace_string(first_number, i, "9")
        elif first_number[i] != "?" and second_number[i] == "?":
            if are_the_same:
                # Keep it that way:
                second_number = replace_string(second_number, i, first_number[i])
            else:
                assert(bigger == 0 or bigger == 1)
                if bigger == 1:
                    # Second one is bigger, make it as small as possible:
                    second_number = replace_string(second_number, i, "0")
                else:
                    second_number = replace_string(second_number, i, "9")
        else:
            # Both are already fixed.
            if first_number[i] != second_number[i]:
                if are_the_same:
                    # Check which one is bigger:
                    are_the_same = False
                    if int(first_number[i]) > int(second_number[i]):
                        bigger = 0
                    else:
                        bigger = 1

    print("Case #" + str(test_case_counter) + ": " + str(first_number) + " " + str(second_number))
