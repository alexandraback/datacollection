def parsing():
    nb_tests = int(raw_input())
    words = []

    for _ in range(nb_tests):
        words.append([])
        nb_str = int(raw_input())
        for _ in range(nb_str):
            words[len(words) - 1].append(raw_input())

    return nb_tests, words

def display(case_number, result):
    print "Case #" + str(case_number) + ": " + str(result)

def solve(case):
    prefixes = [a.split()[0] for a in case]
    prefixes_kept = list(set([a for a in prefixes if prefixes.count(a) > 1]))
    strings_kept = [a for a in case if a.split()[0] in prefixes_kept]
    suffixes = [a.split()[1] for a in case]
    suffixes_kept = list(set([a for a in suffixes if suffixes.count(a) > 1]))
    strings_def_kept = [a for a in case if a.split()[0] in prefixes_kept and a.split()[1] in suffixes_kept]

    count = 0
    whole_prefixes = [a.split()[0] for a in strings_def_kept]
    tmp_prefixes = list(set(whole_prefixes))

    for elem in tmp_prefixes:
        if whole_prefixes.count(elem) == prefixes.count(elem):
            count += whole_prefixes.count(elem) - 1
        else:
            count += whole_prefixes.count(elem)
    
    whole_suffixes = [a.split()[1] for a in strings_def_kept]
    tmp_suffixes = list(set(whole_suffixes))

    for elem in tmp_suffixes:
        if whole_suffixes.count(elem) == suffixes.count(elem):
            for pre in tmp_prefixes:
                if whole_prefixes.count(pre) == prefixes.count(pre) and pre + ' ' + elem in strings_def_kept:
                    break
            else:
                count -= 1

    return count

def main():
    nb_tests, words = parsing()

    for case in range(nb_tests):
        display(case + 1, solve(words[case]))

if __name__=='__main__':
    main()
