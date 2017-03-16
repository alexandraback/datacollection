def flip_pancakes (str_pancake):
    str_pancake = str_pancake[::-1]
    str_pancake = str_pancake.replace('-', '|')
    str_pancake = str_pancake.replace('+', '-')
    str_pancake = str_pancake.replace('|', '+')
    return str_pancake

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    str_pancake = raw_input()
    count = 0
    while '-' in str_pancake:
        first = str_pancake.index('-')
        last = str_pancake.rindex('-')
        if str_pancake[0] == "+":
            str_pancake = flip_pancakes(str_pancake[:first]) + str_pancake[first:]
            count = count + 1
        str_pancake = flip_pancakes(str_pancake[:last + 1]) + str_pancake[last + 1:]
        count = count + 1
    print "Case #{}: {}".format(i, count)
