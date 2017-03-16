#include <array>
#include <iostream>

typedef std::array<char, 16> BoardState;

int ReadInt(std::istream* istream)
{
    int result;
    if ((*istream) >> result) {
        return result;
    }
    throw std::runtime_error("ReadInt");
}

std::string ReadString(std::istream* istream)
{
    std::string result;
    if ((*istream) >> result) {
        return result;
    }
    throw std::runtime_error("ReadString");
}

BoardState ReadBoardState(std::istream* istream)
{
    BoardState result;
    size_t offset = 0;

    for (;;) {
        for (char character : ReadString(istream)) {
            result[offset++] = character;
            if (offset == result.size()) {
                return result;
            }
        }
    }
}

void WriteBoardState(const BoardState& board_state, std::ostream* ostream)
{
    for (size_t i = 0; i < 16; i += 4) {
        ostream->write(board_state.data() + i, 4);
        (*ostream) << '\n';
    }
}




std::string ClassifyBoardState(const BoardState& board_state)
{
    typedef size_t Trace[4];
    const Trace WIN_TRACES[] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15},

        {0, 4, 8, 12},
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15},

        {0, 5, 10, 15},
        {3, 6, 9, 12}
    };

    const auto reduce_owners = [](char left_owner, char right_owner) -> char {
        if (left_owner == right_owner) {
            return left_owner;
        }
        if (left_owner == 'T') {
            return right_owner;
        }
        if (right_owner == 'T') {
            return left_owner;
        }
        return '.';
    };

    for (const auto& win_trace : WIN_TRACES) {
        char trace_owner = 'T';
        for (size_t position : win_trace) {
            trace_owner = reduce_owners(trace_owner, board_state.at(position));
        }
        if (trace_owner == 'X') {
            return "X won";
        } else if (trace_owner == 'O') {
            return "O won";
        }
    }

    if (board_state.end() == std::find(board_state.begin(), board_state.end(), '.')) {
        return "Draw";
    } else {
        return "Game has not completed";
    }
}

int main()
{
    const int number_of_cases = ReadInt(&std::cin);
    for (int case_no = 1; case_no <= number_of_cases; ++case_no) {
        std::cout << "Case #" << case_no << ": "
                  << ClassifyBoardState(ReadBoardState(&std::cin)) << '\n';
    }
    return 0;
}
