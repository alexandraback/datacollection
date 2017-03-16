#include <iostream>
#include <istream>
#include <stdexcept>

class Board
{
    public:
        enum class Mark { X, O, T, EMPTY };
        enum class Status { X_WON, O_WON, DRAW, GAME_NOT_COMPLETED };

    private:
        static const unsigned int boardSize = 4;

        Mark board[boardSize][boardSize];

        bool hasWon(Mark mark);
        bool isFilled();

    public:
        Status getStatus();

        void readBoard(std::istream& stream);
};

bool Board::hasWon(Mark mark)
{
    if(mark != Mark::X && mark != Mark::O)
        throw std::runtime_error("Invalid mark has been given to hasWon");

    // Rows
    for(unsigned int y = 0; y < boardSize; y++)
    {
        unsigned int ownMarkCount = 0;
        unsigned int tCount = 0;

        for(unsigned int x = 0; x < boardSize; x++)
        {
            if(board[x][y] == mark)
            {
                ownMarkCount++;
            }
            else if(board[x][y] == Mark::T)
            {
                tCount++;
            }
        }

        if(ownMarkCount == boardSize
           || (ownMarkCount == boardSize - 1 && tCount == 1))
        {
            return true;
        }
    }

    // Columns
    for(unsigned int x = 0; x < boardSize; x++)
    {
        unsigned int ownMarkCount = 0;
        unsigned int tCount = 0;

        for(unsigned int y = 0; y < boardSize; y++)
        {
            if(board[x][y] == mark)
            {
                ownMarkCount++;
            }
            else if(board[x][y] == Mark::T)
            {
                tCount++;
            }
        }

        if(ownMarkCount == boardSize
           || (ownMarkCount == boardSize - 1 && tCount == 1))
        {
            return true;
        }
    }

    // Left-top to Right-bottom diagonal
    {
        unsigned int ownMarkCount = 0;
        unsigned int tCount = 0;

        for(unsigned int i = 0; i < boardSize; i++)
        {
            unsigned int x = i;
            unsigned int y = i;

            if(board[x][y] == mark)
            {
                ownMarkCount++;
            }
            else if(board[x][y] == Mark::T)
            {
                tCount++;
            }
        }

        if(ownMarkCount == boardSize
           || (ownMarkCount == boardSize - 1 && tCount == 1))
        {
            return true;
        }
    }

    // Right-top to Left-bottom diagonal
    {
        unsigned int ownMarkCount = 0;
        unsigned int tCount = 0;

        for(unsigned int i = 1; i <= boardSize; i++)
        {
            unsigned int x = boardSize - i;
            unsigned int y = i - 1;

            if(board[x][y] == mark)
            {
                ownMarkCount++;
            }
            else if(board[x][y] == Mark::T)
            {
                tCount++;
            }
        }

        if(ownMarkCount == boardSize
           || (ownMarkCount == boardSize - 1 && tCount == 1))
        {
            return true;
        }
    }

    return false;
}

std::istream& operator>>(std::istream& stream, Board::Mark& mark)
{
    char markChar;

    if(stream >> markChar)
    {
        switch(markChar)
        {
            case 'X':
                mark = Board::Mark::X;
                break;

            case 'O':
                mark = Board::Mark::O;
                break;

            case 'T':
                mark = Board::Mark::T;
                break;

            case '.':
                mark = Board::Mark::EMPTY;
                break;

            default:
                stream.setstate(stream.rdstate() | std::ios::failbit);
                break;
        }
    }

    return stream;
}

bool Board::isFilled()
{
    for(unsigned int y = 0; y < boardSize; y++)
    {
        for(unsigned int x = 0; x < boardSize; x++)
        {
            if(board[x][y] == Mark::EMPTY)
                return false;
        }
    }

    return true;
}

Board::Status Board::getStatus()
{
    if(hasWon(Mark::X))
        return Status::X_WON;

    if(hasWon(Mark::O))
        return Status::O_WON;

    if(isFilled())
        return Status::DRAW;

    return Status::GAME_NOT_COMPLETED;
}

void Board::readBoard(std::istream& stream)
{
    for(unsigned int y = 0; y < boardSize; y++)
    {
        for(unsigned int x = 0; x < boardSize; x++)
        {
            std::cin >> board[x][y];
        }
    }
}

std::string solve()
{
    Board board;
    board.readBoard(std::cin);

    switch(board.getStatus())
    {
        case Board::Status::X_WON:
            return "X won";

        case Board::Status::O_WON:
            return "O won";

        case Board::Status::DRAW:
            return "Draw";

        case Board::Status::GAME_NOT_COMPLETED:
            return "Game has not completed";

        default:
            throw std::logic_error("Invalid status has appeared in solve");
    }
}

int main()
{
    unsigned int t;
    std::cin >> t;

    for(unsigned int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }
}
