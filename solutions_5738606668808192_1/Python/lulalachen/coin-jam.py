def baseconverter(raw_number, base):
    digits = "0123456789"
    result = ""
    while 1:
        remains = raw_number % base
        result = digits[remains] + result
        raw_number = raw_number / base
        if raw_number == 0:
            break
    return result

def check_prime_and_factor(raw_number):
    for divisor in xrange(2, 100):
        if not raw_number % divisor:
            return (False, divisor)
    return (True, 1)

lines = raw_input()
for question_index in xrange(1, int(lines) + 1):
    length_of_jamcoin, types_of_jamcoin = [int(s) for s in raw_input().split(" ")]

    answer_list = []
    count = 0
    for index in xrange(1, pow(2, length_of_jamcoin)):
        inside = baseconverter(index, 2)
        if len(str(inside)) < length_of_jamcoin - 1:
            result = str(inside).zfill(length_of_jamcoin - 2)
            temp_testcase = '1' + result + '1'
        answers = temp_testcase

        for i in xrange(2, 11):
            temp = check_prime_and_factor(int(temp_testcase, i))
            if not temp[0]:
                answers += ' ' + str(temp[1])

        if answers.count(' ') >= 9:
            answer_list.append(answers)

        if len(answer_list) >= types_of_jamcoin:
            break
    print 'Case #1:'
    for ans in answer_list:
        print ans


