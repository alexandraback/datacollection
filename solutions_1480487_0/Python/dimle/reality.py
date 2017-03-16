import heapq
import operator


def how_many_votes(s):
    votes = compute_needed_votes(s)
    total = sum(s)
    N = len(s)
    index_score = list(zip(list(range(N)), s))
    #score_index.sort(key=lambda student: student[0])
    index_score.sort(key=lambda student: student[1])
    sorted_index, sorted_s = zip(*index_score)
    sorted_index = list(sorted_index)
    sorted_index2 = sorted_index[:]
    for i, j in enumerate(sorted_index):
        sorted_index2[j] = i
    percentage = []
    for i in range(N):
        j = sorted_index2[i]
        try:
            a = sum(votes[j:])
        except IndexError:
            a = 0
        percentage.append(100 *a/total)

    return percentage

def compute_needed_votes(s):
    remaining_points = sum(s)
    previous_p = 0
    difference = []

    sorted_s = sorted(s)
    for i, p in enumerate(sorted_s):
        # warning: i is 0 based
        if remaining_points <= 0:
            break
        if i == 0: # first player
            previous_p = p
            continue
        if i*(p - previous_p) > remaining_points:
            difference.append(remaining_points/i)
            remaining_points = 0
            break
        difference.append(p - previous_p)
        remaining_points -= i*(p - previous_p)
        previous_p = p

    if remaining_points > 0:
        difference.append(remaining_points/len(s))

    return difference

def main():
    testcases = int(input())
    for i in range(1, testcases + 1):
        a = [int(x) for x in input().split()]
        N, s = a[0], a[1:]
        print('Case #' + str(i) + ': ', end='')
        votes = how_many_votes(s)
        for v in votes:
            print(str(v), end=' ')
        print()

if __name__ == '__main__':
    main()
    

