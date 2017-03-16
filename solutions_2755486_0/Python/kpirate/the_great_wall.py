# Problem C. The Great Wall

##Problem
##
##You are studying the history of the Great Wall of China, which was built by the Chinese to protect against military incursions from the North. For the purposes of this problem, the Great Wall stretches from infinity in the East to minus infinity in the West. As this is a lot of distance to cover, the Great Wall was not built at once. Instead, for this problem we assume that the builder used a reactive strategy: whenever a part of the border was attacked successfully, the Wall on this part of the border would be raised to the height sufficient to stop an identical attack in the future.
##
##The north border of China was frequently attacked by nomadic tribes. For the purposes of this problem, we assume that each tribe attacks the border on some interval with some strength S. In order to repel the attack, the Wall must have height S all along the defended interval. If even a short stretch of the Wall is lower than needed, the attack will breach the Wall at this point and succeed. Note that even a successful attack does not damage the Wall. After the attack, every attacked fragment of the Wall that was lower than S is raised to height S — in other words, the Wall is increased in the minimal way that would have stopped the attack. Note that if two or more attacks happened on the exact same day, the Wall was raised only after they all resolved, and is raised in the minimum way that would stop all of them.
##
##Since nomadic tribes are nomadic, they did not necessarily restrict themselves to a single attack. Instead, they tended to move (either to the East or to the West), and periodically attack the Wall. To simplify the problem, we assume they moved with constant speed and attacked the Wall at constant intervals; moreover we assume that the strength with which a given tribe attacked the Wall changed by a constant amount after each attack (either decreased from attrition, or grew from experience).
##
##Assuming that initially (in 250 BC) the Wall was nonexistent (i.e., of height zero everywhere), and given the full description of all the nomadic tribes that attacked the Wall, determine how many of the attacks were successful.
##
##Input
##
##The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing a single integer N: the number of the tribes attacking the Wall. N lines follow, each describing one tribe. The ith line contains eight integers di, ni, wi, ei, si, delta_di, delta_pi and delta_si separated by spaces, describing a single nomadic tribe:
##
##di – the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
##ni – the number of attacks from this tribe
##wi, ei – the westmost and eastmost points respectively of the Wall attacked on the first attack
##si – the strength of the first attack
##delta_di – the number of days between subsequent attacks by this tribe
##delta_pi – the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
##delta_si – the change in strength between subsequent attacks
##Output
##
##For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the number of attacks that succeed.
##
##Limits
##
##1 ≤ T ≤ 20.
##0 ≤ di.
##1 ≤ delta_di ≤ 676060.
##di + (ni - 1) * delta_di ≤ 676060.
##1 ≤ si ≤ 106.
##-105 ≤ delta_si ≤ 105.
##si + (ni - 1) * delta_si ≥ 1.
##
##Small dataset
##
##1 ≤ N ≤ 10.
##1 ≤ ni ≤ 10.
##-100 ≤ wi < ei ≤ 100.
##-10 ≤ delta_pi ≤ 10.
##Large dataset
##
##1 ≤ N ≤ 1000.
##1 ≤ ni ≤ 1000.
##-106 ≤ wi < ei ≤ 106.
##-105 ≤ delta_pi ≤ 105.

debug = False

# Get input file
input_fname = input("Input filename: ")
infile = open(input_fname, 'r')
# Set output file
output_fname = input_fname.replace("in", "out")
outfile = open(output_fname, 'w')

T = int(infile.readline().strip("\n"))

for casenum in range(T):
    print("Case #", casenum+1, ": ", sep="", end="", file=outfile)

    days = []
    attacks = []
    ranges = []
    strengths = []
    time_steps = []
    distances = []
    strength_changes = []

    # Initialize the wall to zero height. west covers negative indexes
    east_wall = [0] * 10001
    west_wall = [0] * 10000
    hits = 0

    N = int(infile.readline().strip("\n"))
    for index in range(N):
        d_i, n_i, w_i, e_i, s_i, delta_d_i, delta_p_i, delta_s_i = \
             [int(x) for x in infile.readline().strip("\n").split(" ")]
        days.append(d_i)
        attacks.append(n_i)
        ranges.append([w_i, e_i])
        strengths.append(s_i)
        time_steps.append(delta_d_i)
        distances.append(delta_p_i)
        strength_changes.append(delta_s_i)

    # Look to see what is the next day we need to handle
    next_day = min(days)
    updates = []
    while next_day <= 676060:
        # 676060 is given as the max possible day
        tribe = days.index(next_day)
        west, east = ranges[tribe]
        strength = strengths[tribe]

        # See if it hit
        for index in range(west + 1, east + 1):
            if index < 0 and west_wall[-index] < strength:
                hits += 1
                updates.append([west, east, strength])
                if debug:
                    print("Hit by tribe", tribe+1, "on day", next_day, \
                          "at position", index, "with attack of strength",
                          strength, "where wall has strength", \
                          west_wall[-index])
                break
            if index >= 0 and east_wall[index] < strength:
                hits += 1
                updates.append([west, east, strength])
                if debug:
                    print("Hit by tribe", tribe+1, "on day", next_day, \
                          "at position", index, "with attack of strength",
                          strength, "where wall has strength", \
                          east_wall[index])
                break

        # Now, update this tribe's data
        attacks[tribe] -= 1
        if attacks[tribe] > 0:
            days[tribe] += time_steps[tribe]
            ranges[tribe] = [west + distances[tribe], east + distances[tribe]]
            strengths[tribe] += strength_changes[tribe]
        else:
            days[tribe] = 1000000

        # Look to see what day is next
        new_next_day = min(days)
        if new_next_day > next_day:
            # Handle all the updates for this day
            for update in updates:
                for index in range(update[0] + 1, update[1] + 1):
                    if index < 0:
                        west_wall[-index] = max(west_wall[-index], update[2])
                    else:
                        east_wall[index] = max(east_wall[index], update[2])
            # Now clear out updates and prepare for the next day
            next_day = new_next_day
            updates = []

    print(hits, file=outfile, end="")
    if debug:
        print()
        
    print("", file=outfile)
# end case loop

infile.close()
outfile.close()
