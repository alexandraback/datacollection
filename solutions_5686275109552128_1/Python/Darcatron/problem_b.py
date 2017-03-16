"""
Problem B
"""

def InfiniteHouseOfPancakes():
    """
    Main function call CamelCased like a badass
    """

    NUMB_TRIALS = raw_input()

    for trial in range(int(NUMB_TRIALS)):
        numb_diners = int(raw_input())
        diners_list = [int(x) for x in raw_input().split(' ')]
        numb_splits = 0 # numb of special minutes used
        min_time = max(diners_list) # min time needed to finish

        # all diners must be at most one pancake apart
        while check_split(diners_list, numb_diners):
            split(diners_list)
            numb_diners += 1
            numb_splits += 1
            time_needed = max(diners_list) + numb_splits
            # print "time needed: " + str(time_needed) + "  min_time: " + str(min_time)
            min_time = time_needed if time_needed < min_time else min_time

        # output number of special minutes plus max pancake stack
        print "Case #" + str(trial + 1) + ": " + str(min_time)

def test():
    for t in range(int(raw_input())):

        D = int (raw_input())

        P = list (map(int, raw_input().split(' ')))

        # Result is clearly up to no more than max (P), which is totally not the case assignment
        ans = max(P)

        # Traversing block allocation size, and then optimize the time
        Z = 2
        while Z < ans:
            ans = min(ans, sum([(x - 1) // Z for x in P]) + Z)
            Z += 1

        print 'Case #%d: %s' % (t + 1, ans)


def check_split(diners_list, numb_diners):
    """
    checks to see if split is needed
    returns number of splits done which is the number of special minutes used
    """

    ####################### OLD METHOD -- failed :( ##################################
    # if numb_diners == 1:
    #     min_for_split = 4

    #     if diners_list[0] >= min_for_split:
    #         # split(diners_list)
    #         # return check_split(diners_list, numb_diners + 1) + 1
    #         return True

    # diners_list.sort(reverse=True)

    # cur_index = 0
    # for diner in diners_list:
        # each diner can have at most one more pancake than another diner
        # if cur_index + 1 < (numb_diners) and diners_list[cur_index + 1] + 1 < diner:
            # split max into 2 and run again
            # split(diners_list)
            # return check_split(diners_list, numb_diners + 1) + 1
        # cur_index += 1
    ##################################################################################

    diners_list.sort(reverse=True)
    min_for_split = 4 # min stack needed to check for split

    if diners_list[0] >= min_for_split:
        return True

    return False


def split(diners_list):
    """
    split biggest into two stacks
    Pre-Condition: diners_list is sorted in reverse order
    """

    biggest_stack = diners_list.pop(0)

    # add first split
    diners_list.append(biggest_stack / 2)

    if biggest_stack % 2 == 0:
        # add even split
        diners_list.append(biggest_stack / 2)
    else:
        # add odd split
        diners_list.append(biggest_stack - (biggest_stack / 2))


# InfiniteHouseOfPancakes()
test()
