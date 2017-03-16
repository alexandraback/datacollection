#include "common.hpp"
#include <fstream>

using namespace std;


codejam::codejam(std::string problem)
        : problem(problem), attempt(-1) {}

std::string codejam::create_input_filename(int attempt_no)
    {
        std::stringstream buffer;
        buffer << datasetdir << '/'
               << problem
               << '-' << dataset
               << "-attempt" << attempt_no
               << ".in";
        return buffer.str();
    }

bool codejam::file_exists(std::string filename) {
        std::ifstream tmp(filename.c_str());
        return tmp;
    }

bool codejam::detect_attempt() {
        if(attempt < 0) {
            int attempt_no=0;
            for(; attempt_no < 100; ++attempt_no) {
                std::string input = create_input_filename(attempt_no);
                if(! file_exists(input))
                    break;
            }
            -- attempt_no;
            attempt = attempt_no;
            if(attempt >= 0)
                std::cerr << "Auto-detected attempt #" << attempt << std::endl;
        }
        return (attempt >= 0
                && file_exists(create_input_filename(attempt)));
    }

void codejam::show_help()
    {
        std::cerr
            << "Usage: " << progname << " -h"
                                     << "\n"
            << "       " << progname << " [OPTIONS] "
                                     << "[-i <file.in>] "
                                     << "[-o <file.out>] "
                                     << "\n"
            << "\n"
            << "OPTIONS: \n"
            << " -d <dir> Use <dir> as testcase directory\n"
            << " -s       Use small dataset \n"
            << " -l       Use large dataset \n"
            << " -<n>     Use input for attempt <n>\n"
            << "\n"
            << "ENVIRONMENT VARIABLES\n"
            << "\n"
            << " - CODEJAM_SRC  Contains the default path to the testcase\n"
            << "                directory\n"
            << std::endl;
    }

int codejam::run(int argc, char* argv[])
    {
        progname   = argv[0];
        datasetdir = "";
        dataset    = "small";
        attempt    = -1;

        auto env_datasetdir = std::getenv("CODEJAM_SRC");
        if(env_datasetdir)
            datasetdir = env_datasetdir;
        
        std::string::size_type idx = progname.rfind('/');
        if(std::string::npos == idx) {
            idx = progname.rfind('\\');
        }
        if(std::string::npos != idx) {
            if(datasetdir.empty())
                datasetdir = progname.substr(0,idx);
            progname   = progname.substr(idx+1);
        }

        if(datasetdir.empty())
            datasetdir = ".";

        std::string input    = "";
        std::string output   = "";

        std::queue<std::string> args;
        for(int i=1; i<argc; ++i)
            args.push(argv[i]);
        args.push("");
        while(! args.empty()) {
            std::string const opt = args.front();
            args.pop();

            if(opt.empty())
                continue;

            if(opt == "-h") {
                show_help();
                return 0;
            }
            else if(opt == "-d") {
                datasetdir = args.front();
                args.pop();
            }
            else if(opt == "-i") {
                input = args.front();
                args.pop();
            }
            else if(opt == "-o") {
                output = args.front();
                args.pop();
            }
            else if(opt == "-s") {
                dataset = "small";
            }
            else if(opt == "-l") {
                dataset = "large";
            }
            else {
                std::stringstream buffer(opt.substr(1));
                if(! (buffer >> attempt)) {
                    std::cerr << "Unrecognized option: " << opt << std::endl;
                    show_help();
                    return 1;
                }
            }
        }

        if(input.empty()) {
            if(! detect_attempt())
            {
                std::cerr << "Unable to auto-detect attempt-no" << std::endl;
                show_help();
                return -1;
            }
            input = create_input_filename(attempt);
        }

        if(output.empty()) {
            idx = input.rfind('.');
            if(std::string::npos == idx || input.substr(idx) != ".in")
                idx = input.size();
            output  = input.substr(0, idx);

            std::string ext = ".out";
            for(int backno=2; file_exists(output+ext); ++backno) {
                std::stringstream buffer;
                buffer << ".out" << backno;
                ext = buffer.str();
            }
            output += ext;
        }

        std::istream* p_in  = & std::cin;
        std::ostream* p_out = & std::cout;

        std::ifstream f_in;
        std::ofstream f_out;

        if(input != "-") {
            std::cerr << "Reading file: " << input << std::endl;
            f_in.open(input.c_str());
            if(! f_in) {
                std::cerr << "Unable to open input file: " << input << std::endl;
                return 1;
            }
            p_in = &f_in;
        }
        if(output != "-") {
            std::cerr << "Writing file: " << output << std::endl;
            f_out.open(output.c_str());
            if(! f_out) {
                std::cerr << "Unable to open output file: " << output << std::endl;
                return 1;
            }
            p_out = &f_out;
        }

        string line;
        std::getline(*p_in, line);
        std::stringstream buffer(line);
        int T;
        buffer >> T;
        for(int t=1; t<=T; ++t) {
            if(dataset == "small")
                solve_small(t, *p_in, *p_out);
            if(dataset == "large")
                solve_large(t, *p_in, *p_out);
        }
        return 0;
    }

