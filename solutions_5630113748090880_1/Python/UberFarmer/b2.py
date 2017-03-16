from sys import stdin

DEBUG = False


def debug_print(*args):
    if DEBUG:
        print args

def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):
        N = int(stdin.readline().strip())

        papers = []
        for _ in range(2 * N - 1):
            papers.append(map(int, stdin.readline().strip().split()))

        papers.sort()
        debug_print(papers)

        grid = []
        for _ in range(N):
            grid.append([None]*N)

        pairs = []
        for index in range(N):
            min_value_at_index = 3000
            for paper in papers:
                min_value_at_index = min(paper[index], min_value_at_index)

            pair = []
            for paper in papers:
                if paper[index] == min_value_at_index:
                    pair.append(paper)
            for paper in pair:
                papers.remove(paper)

            pairs.append(pair)

        debug_print("pairs", papers, pairs)

        for i, pair in enumerate(pairs):
            if len(pair) is 1:
                present_paper = pair[0]
                missing_pair_index = i

        missing_paper = []
        for i, pair in enumerate(pairs):
            if i == missing_pair_index:
                missing_paper.append(present_paper[missing_pair_index])
            else:
                present_num = present_paper[i]
                choice_1 = pair[0][missing_pair_index]
                choice_2 = pair[1][missing_pair_index]
                if choice_1 == present_num:
                    missing_paper.append(choice_2)
                else:
                    missing_paper.append(choice_1)

        print "Case #{}: {}".format(case, ' '.join(map(str, missing_paper)))

if __name__ == "__main__":
    main()
