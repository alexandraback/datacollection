def get_digits(word_str):
    char_dict = {}
    for char in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        char_dict[char] = 0
    digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for char in word_str:
        char_dict[char] += 1

    zero_num = char_dict['Z']
    digits[0] += zero_num
    for char in 'ZERO':
        char_dict[char] -= zero_num

    two_num = char_dict['W']
    digits[2] += two_num
    for char in 'TWO':
        char_dict[char] -= two_num

    four_num = char_dict['U']
    digits[4] += four_num
    for char in 'FOUR':
        char_dict[char] -= four_num

    six_num = char_dict['X']
    digits[6] += six_num
    for char in 'SIX':
        char_dict[char] -= six_num

    seven_num = char_dict['S']
    digits[7] += seven_num
    for char in 'SEVEN':
        char_dict[char] -= seven_num

    eight_num = char_dict['G']
    digits[8] += eight_num
    for char in 'EIGHT':
        char_dict[char] -= eight_num

    three_num = char_dict['T']
    digits[3] += three_num
    for char in 'THREE':
        char_dict[char] -= three_num

    five_num = char_dict['V']
    digits[5] += five_num
    for char in 'FIVE':
        char_dict[char] -= five_num

    nine_num = char_dict['I']
    digits[9] += nine_num
    for char in 'NINE':
        char_dict[char] -= nine_num

    one_num = char_dict['O']
    digits[1] += one_num

    output = ''
    for digit in range(len(digits)):
        for i in range(digits[digit]):
            output += str(digit)

    return output


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        word_str = input()
        output = get_digits(word_str)
        print('Case #{}: {}'.format(i + 1, output))
