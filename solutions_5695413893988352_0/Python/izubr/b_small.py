

def form_result(result_code, result_jam, case):
    print "Case #%s: %s %s" % (case + 1, result_code, result_jam)

def form_equal_answer(code, jam):
    answer = ""
    for i, c in enumerate(code):
        j = jam[i]
        if c == '?':
            if j == '?':
                answer += '0'
            else:
                answer += j
        elif j == '?' or j == c:
            answer += c
        else:
            return None
    return answer

def to_full_string(s, l):
    return (l - len(str(s))) * '0' + str(s)

def character_indexes(s):
    res = []
    for i, _ in enumerate(s):
        if s[i] != '?':
            res.append(i)
    return res

def form_list(s):
    l = len(s)
    all_res = range(10**l)
    result = []
    for res in all_res:
        to_add = True
        res = to_full_string(res, l)
        for i in character_indexes(s):
            if s[i] != res[i]:
                to_add = False
        if to_add:
            result.append(res)
    return result

def diff(c, j):
    return abs(int(c) - int(j))


t = int(raw_input(""))
for case in range(t): 
    s = raw_input("")
    code, jam = s.split(" ")
    l = len(code)
    result = form_equal_answer(code, jam)
    if not (result is None):
        form_result(result, result, case)
        continue
    min_diff = 1000000
    best_code = "1000"
    best_jam = "1000"

    codes = form_list(code)
    jams = form_list(jam)

    for c in codes:
        for j in jams:
            cur_dif = diff(c, j)
            if cur_dif < min_diff or \
                (cur_dif == min_diff and int(c) < int(best_code)) or \
                (cur_dif == min_diff and int(c) == int(best_code) and int(j) < int(best_jam)):
                    min_diff = cur_dif
                    best_code = c
                    best_jam = j
    form_result(best_code, best_jam, case)


