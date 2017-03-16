## Problem A. Consonants

##Problem
##
##In English, there are 26 letters that are either vowels or consonants. In this problem, we consider a, e, i, o, and u to be vowels, and the other 21 letters to be consonants.
##
##A tribe living in the Greatest Colorful Jungle has a tradition of naming their members using English letters. But it is not easy to come up with a good name for a new member because it reflects the member's social status within the tribe. It is believed that the less common the name he or she is given, the more socially privileged he or she is.
##
##The leader of the tribe is a professional linguist. He notices that hard-to-pronounce names are uncommon, and the reason is that they have too many consecutive consonants. Therefore, he announces that the social status of a member in the tribe is determined by its n-value, which is the number of substrings with at least n consecutive consonants in the name. For example, when n = 3, the name "quartz" has the n-value of 4 because the substrings quartz, uartz, artz, and rtz have at least 3 consecutive consonants each. A greater n-value means a greater social status in the tribe. Two substrings are considered different if they begin or end at a different point (even if they consist of the same letters), for instance "tsetse" contains 11 substrings with two consecutive consonants, even though some of them (like "tsetse" and "tsetse") contain the same letters.
##
##All members in the tribe must have their names and n given by the leader. Although the leader is a linguist and able to ensure that the given names are meaningful, he is not good at calculating the n-values. Please help the leader determine the n-value of each name. Note that different names may have different values of n associated with them.
##
##Input
##
##The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case gives the name of a member as a string of length L, and an integer n. Each name consists of one or more lower-case English letters.
##
##Output
##
##For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the n-value of the member's name.
##
##Limits
##
##1 ≤ T ≤ 100.
##0 < n ≤ L.
##Small dataset
##
##1 ≤ L ≤ 100.
##Large dataset
##
##1 ≤ L ≤ 106.
##The input file will be no larger than 6MB.

def consecutive_consonant_starts(name, n):
    """Return a list of locations (indexes) in the name where runs of n or
    more consonants begin."""

    starts = []
    for index in range(len(name) - (n-1)):
        substr = name[index:index + n]
        if 'a' not in substr and 'e' not in substr and 'i' not in substr \
           and 'o' not in substr and 'u' not in substr:
            starts.append(index)
    return starts
# end consecutive_consonant_starts

# Get input file
input_fname = input("Input filename: ")
infile = open(input_fname, 'r')
# Set output file
output_fname = input_fname.replace("in", "out")
outfile = open(output_fname, 'w')

T = int(infile.readline().strip("\n"))

for casenum in range(T):
    print("Case #", casenum+1, ": ", sep="", end="", file=outfile)

    name, n = infile.readline().strip("\n").split(" ")
    n = int(n)

    # Find where all the substrings we care about start
    starts = consecutive_consonant_starts(name, n)
    # Now, we can count cases
    count = 0
    # Consider all the possible starting indices
    for index in range(len(name) - (n-1)):
        # If there are no more proper substrings ahead of us, quit
        if len(starts) == 0:
            break

        # Is the next substring still available for use?
        if starts[0] < index:
            starts.pop(0)

        # If there are no more proper substrings ahead of us, quit
        if len(starts) == 0:
            break

        # Otherwise, we can start here, and end anywhere after this substring
        count += (len(name) - starts[0]) - (n - 1)

    print(count, end="", file=outfile)
        
    print("", file=outfile)
# end case loop

infile.close()
outfile.close()
