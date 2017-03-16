def StandingOvation():
    """
    For each test case, output one line containing "Case #x: y",
    where x is the test case number (starting from 1) and y is
    the minimum number of friends you must invite.
    """

    NUMB_TRIALS = raw_input()
    for trial in range(int(NUMB_TRIALS)):
        input_line = raw_input().split(' ')
        max_shyness = input_line[0]
        shyness_list = input_line[1]
        numb_standing = 0
        numb_friends_needed = 0
        cur_shyness_level = 0

        for numb_people in shyness_list:
            if numb_standing < cur_shyness_level:
                # not enough people standing up, add appropriate numb of friends
                numb_friends_needed += cur_shyness_level - numb_standing
                # friends are now standing and so will more people
                numb_standing += (cur_shyness_level - numb_standing) + int(numb_people)
            else:
                # more people will stand
                numb_standing += int(numb_people)

            # next position in shyness_list
            cur_shyness_level += 1

        print "Case #" + str(trial + 1) + ": " + str(numb_friends_needed)

StandingOvation()
