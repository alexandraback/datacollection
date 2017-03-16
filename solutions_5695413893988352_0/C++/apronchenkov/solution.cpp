#include <cassert>
#include <iostream>
#include <string>

std::string Minimize(std::string string) {
    for (auto& c : string) {
        if (c == '?') {
            c = '0';
        }
    }
    return string;
}

std::string Maximize(std::string string) {
    for (auto& c : string) {
        if (c == '?') {
            c = '9';
        }
    }
    return string;
}


long long Parse(const std::string& string) {
    long long result = 0;
    for (auto c : string) {
        result = 10 * result + (c - '0');
    }
    return result;
}


void OptimizeGaps(const std::string& left, const std::string& right, std::string* fixed_left, std::string* fixed_right) {
    std::string best_left = Maximize(left);
    std::string best_right = Minimize(right);
    long best_diff = std::abs(Parse(best_left) - Parse(best_right));

    const auto update = [&](const std::string& new_left, const std::string& new_right) {
        //std::cerr << '!' << new_left << ' ' << new_right << '\n';
        const auto new_left_value = Parse(new_left);
        const auto new_right_value = Parse(new_right);
        if (std::abs(new_left_value - new_right_value) < best_diff ||
            (std::abs(new_left_value - new_right_value) == best_diff && new_left < best_left) ||
            (std::abs(new_left_value - new_right_value) == best_diff && new_left == best_left && new_right < best_right)) {
            best_left = new_left;
            best_right = new_right;
            best_diff = std::abs(new_left_value - new_right_value);
        }
    };

    const auto boost = [&](const std::string& common_prefix, const std::string& left_tail, const std::string& right_tail) {
        update(common_prefix + Minimize(left_tail), common_prefix + Maximize(right_tail));
        update(common_prefix + Maximize(left_tail), common_prefix + Minimize(right_tail));
    };

    std::string common_prefix;

    size_t i = 0;
    while (i < left.size()) {
        if (left[i] == '?' && right[i] == '?') {
            boost(common_prefix, "0" + left.substr(i + 1), "1" + right.substr(i + 1));
            boost(common_prefix, "1" + left.substr(i + 1), "0" + right.substr(i + 1));
            common_prefix += '0';
            
        } else if (left[i] == '?') {
            auto left_tmp = left.substr(i);
            if (right[i] > '0') {
                left_tmp[0] = right[i] - 1;
                boost(common_prefix, left_tmp, right.substr(i));
            }
            if (right[i] < '9') {
                left_tmp[0] = right[i] + 1;
                boost(common_prefix, left_tmp, right.substr(i));
            }
            common_prefix += right[i];
            
        } else if (right[i] == '?') {
            auto right_tmp = right.substr(i);
            if (left[i] > '0') {
                right_tmp[0] = left[i] - 1;
                boost(common_prefix, left.substr(i), right_tmp);
            }
            if (left[i] < '9') {
                right_tmp[0] = left[i] + 1;
                boost(common_prefix, left.substr(i), right_tmp);
            }
            common_prefix += left[i];
            
        } else if (left[i] == right[i]) {
            common_prefix += left[i];
            
        } else {
            break;
        }
        ++i;
    }
    boost(common_prefix, left.substr(i), right.substr(i));
    *fixed_left = best_left;
    *fixed_right = best_right;
}

int main() {
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        std::string left, right;
        std::cin >> left >> right;
        std::string fixed_left, fixed_right;
        OptimizeGaps(left, right, &fixed_left, &fixed_right);
        std::cout << "Case #" << case_no + 1 << ": " << fixed_left << ' ' << fixed_right << '\n';
    }
    return 0;
}
